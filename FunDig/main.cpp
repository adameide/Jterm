/**
 * This is the starting point for all new projects.  This file's purpose is
 * pretty small, but important.  In here we create our application and begin
 * the primary game loop.
 *
 * @file main.cpp
 * @author Ryan Lindeman
 * @date 20100707 - Initial Release
 * @date 20110611 - Added new logging capabilities using macros and c++ classes.
 */

#include <assert.h>
#include <stddef.h>
#include <GQE/Core.hpp>
#include <MyApplication.hpp>

int main(int argc, char* argv[])
{
  // Default anExitCode to a specific value
  int anExitCode = GQE::StatusNoError;

  // Create our Logger first before creating our application
  GQE::FileLogger anLogger("output.txt", true);

  // Create our action application.
  GQE::IApp* anApp = new(std::nothrow) GQE::MyApplication();
  assert(NULL != anApp && "main() Can't create Application");

  // Process command line arguments
  anApp->ProcessArguments(argc, argv);

  // Start the action application:
  // Initialize the action application
  // Enter the Game Loop where the application will remain until it is shutdown
  // Cleanup the action application
  // Exit back to here
  anExitCode = anApp->Run();

  // Cleanup ourselves by deleting the action application
  delete anApp;

  // Don't keep pointers to objects we have just deleted
  anApp = NULL;

  // return our exit code
  return anExitCode;
}
