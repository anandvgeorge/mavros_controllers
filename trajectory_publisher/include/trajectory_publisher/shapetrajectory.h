//
// Created by jalim on 11.10.18.
//

#ifndef TRAJECTORY_PUBLISHER_SHAPETRAJECTORY_H
#define TRAJECTORY_PUBLISHER_SHAPETRAJECTORY_H

#include "trajectory_publisher/trajectory.h"

#define TRAJ_ZERO 0
#define TRAJ_POLYNOMIAL 1
#define TRAJ_CIRCLE 2
#define TRAJ_LAMNISCATE 3

class shapetrajectory : public trajectory {
private:
  int type_;
  int N;
  double dt_;
  double T_;
  int target_trajectoryID_;
  Eigen::Vector3d traj_axis_;
  Eigen::Vector3d target_initpos;
  double traj_radius_, traj_omega_;

public:
  shapetrajectory(int type);
  virtual ~shapetrajectory();
  void setTrajectory(int ID);
  void setTrajectory(int ID, double omega, Eigen::Vector3d axis, double radius, Eigen::Vector3d initpos);
  Eigen::VectorXd getCoefficients(int dim);
  Eigen::Vector3d getPosition(double time);
  Eigen::Vector3d getVelocity(double time);
  nav_msgs::Path getSegment();
  geometry_msgs::PoseStamped vector3d2PoseStampedMsg(Eigen::Vector3d position, Eigen::Vector4d orientation);

};
#endif //TRAJECTORY_PUBLISHER_SHAPETRAJECTORY_H
