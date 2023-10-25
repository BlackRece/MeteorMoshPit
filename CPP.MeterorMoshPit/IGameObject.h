#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

class IGameObject
{
public:
	~IGameObject() = default;

	virtual void Update(float fDelta) = 0;

private:

};

#endif // !IGAMEOBJECT_H
