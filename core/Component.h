#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void initialize() = 0;
	virtual void execute() = 0;
	virtual void shutdown() = 0;
};

#endif
