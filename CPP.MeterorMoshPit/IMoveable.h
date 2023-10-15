#ifndef IMOVEABLE_H
#define IMOVEABLE_H

class IMoveable
{
public:
	virtual ~IMoveable() {};

	virtual void MoveForward(float fDelta, float fSpeed) = 0;
	virtual void Rotate(float fAngle) = 0;
	virtual void Update(float fDelta) = 0;

private:
};

#endif // !IMOVEABLE_H
