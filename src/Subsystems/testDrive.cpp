#include "testDrive.h"
#include "../RobotMap.h"
#include "../DriveFive.h"

testDrive::testDrive() : Subsystem("testDrive"), leftMotor(new TalonSRX), rightMotor(new TalonSRX), leftEncoder(new Encoder(ENCODER_LEFT_1, ENCODER_LEFT_2)), rightEncoder(new Encoder(ENCODER_RIGHT_1, ENCODER_RIGHT_2)), mult(1.0), ticksToDistance(114){
	leftEncoder->SetDistancePerPulse(1.0);
	rightEncoder->SetDistancePerPulse(1.0);
}

testDrive::~testDrive()
{
	delete leftMotor;
	delete rightMotor;
	delete leftEncoder;
	delete rightEncoder;
}

void testDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveFive());
}

void testDrive::resetEncoders()
{
	leftEncoder->Reset();
	rightEncoder->Reset();
}

double DriveTrain::getDistance() {
	// Average of both encoders (must negate to get proper direction)
	return ((double) ((encoderLeft->Get()) / ticksToDistance)
			- (double) ((encoderRight->Get()) / ticksToDistance)) / 2.0;
}

void DriveTrain::setSpeedLeft(double speed) {
	left->SetSpeed(speed * mult);
}

void DriveTrain::setSpeedRight(double speed) {
	right->SetSpeed(speed * mult);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.                                                                                                                                                                                                                                                                                                                                                                                      
