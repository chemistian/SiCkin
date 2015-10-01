#ifndef SICKINAPP_H
#define SICKINAPP_H

#include "MooseApp.h"

class SickinApp;

template<>
InputParameters validParams<SickinApp>();

class SickinApp : public MooseApp
{
public:
  SickinApp(InputParameters parameters);
  virtual ~SickinApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* SICKINAPP_H */
