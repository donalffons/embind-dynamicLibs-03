#ifndef _BRepTools_History_HeaderFile
#define _BRepTools_History_HeaderFile

#include <TopTools_DataMapOfShapeListOfShape.hxx>
class BRepTools_History: public Standard_Transient
{
public:
  BRepTools_History() {}

private:
  static const TopTools_ListOfShape myEmptyList;
};

#endif
