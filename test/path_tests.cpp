
/*
Copyright (c) 2020 Michael E. Ferguson. All right reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <gtest/gtest.h>
#include <robomagellan/path.hpp>

TEST(PathTests, update_headings)
{
  Path path;
  path.waypoints.push_back(waypointFromPose(0.0, 0.0, 0.0));

  // Cannot set headings without at least two points
  EXPECT_FALSE(setHeadings(path));

  path.waypoints.push_back(waypointFromPose(1.0, 0.0, 0.0));
  path.waypoints.push_back(waypointFromPose(1.5, 0.5, 0.0));
  path.waypoints.push_back(waypointFromPose(1.5, 1.0, 0.0));
  path.waypoints.push_back(waypointFromPose(1.0, 1.0, 0.0));

  EXPECT_TRUE(setHeadings(path));

  EXPECT_DOUBLE_EQ(path.waypoints[0]->heading, 0.0);
  EXPECT_DOUBLE_EQ(path.waypoints[1]->heading, M_PI / 4.0);
  EXPECT_DOUBLE_EQ(path.waypoints[2]->heading, M_PI / 2.0);
  EXPECT_DOUBLE_EQ(path.waypoints[3]->heading, M_PI);
  EXPECT_DOUBLE_EQ(path.waypoints[4]->heading, M_PI);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

