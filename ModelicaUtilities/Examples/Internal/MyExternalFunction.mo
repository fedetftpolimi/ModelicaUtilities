within ModelicaUtilities.Examples.Internal;
function MyExternalFunction

  input Real u;
  output Real y;

  external "C" y = MyExternalFunction(u, ModelicaUtilities.callbacks) annotation (
    Library={"MyExternalLibrary"});

end MyExternalFunction;
