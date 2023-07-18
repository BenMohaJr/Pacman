#include "ObjectsInc/StaticObject.h"


//Changes the object to be deleted.
void StaticObject::Dispose()
{
	m_isDisposed = true;
}
//Returns whether the object should be deleted.
bool StaticObject::isDisposed()
{
	return m_isDisposed;
}


