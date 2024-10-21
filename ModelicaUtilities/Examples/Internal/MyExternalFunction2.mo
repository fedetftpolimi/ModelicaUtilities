within ModelicaUtilities.Examples.Internal;
function MyExternalFunction2

  input Real u;
  output Real y;

  external "C" y = MyExternalFunction(u, callbacks) annotation (
    Library={"MyExternalLibrary"});

end MyExternalFunction2;