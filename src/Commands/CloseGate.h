#ifndef CloseGate_H
#define CloseGate_H

#include "../CommandBase.h"

class CloseGate: public CommandBase {
public:
	CloseGate();
	void Initialize();
	void Execute();bool IsFinished();
	void End();
	void Interrupted();
	bool finished;
};

#endif  // CloseGate_H
