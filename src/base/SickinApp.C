#include "SickinApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "LaplaceYoung.h"

template<>
InputParameters validParams<SickinApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SickinApp::SickinApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  SickinApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  SickinApp::associateSyntax(_syntax, _action_factory);
}

SickinApp::~SickinApp()
{
}

// External entry point for dynamic application loading
extern "C" void SickinApp__registerApps() { SickinApp::registerApps(); }
void
SickinApp::registerApps()
{
  registerApp(SickinApp);
}

// External entry point for dynamic object registration
extern "C" void SickinApp__registerObjects(Factory & factory) { SickinApp::registerObjects(factory); }
void
SickinApp::registerObjects(Factory & factory)
{
  registerKernel(LaplaceYoung);
}

// External entry point for dynamic syntax association
extern "C" void SickinApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SickinApp::associateSyntax(syntax, action_factory); }
void
SickinApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
