#include "GameState.h"
#include "Window.h"
#include <vector>

namespace hm
{
	class StateManager // Handles the switching of states.
	{
		public:
			StateManager(); // Basic constructor.
			StateManager(Window* window); // Constructor sets window to use.

			void startState(); // Starts the state on the top of the stack.
			void stopState(); // Stops the state on the top of the stack.
			void resumeState(); // Restarts the state on the top of the stack.
			void pauseState(); // Pause the state at the top of the stack.

			GameState* getCurrentState(); // Returns a pointer to the current state.

			void pushState(GameState& gs); // Adds a state to the stack.
			void popState(); // Pops a state from the stack.
			void replaceState(GameState& gs); // Switches out a state.
			void popAll(); // Removes all states. Takes care of cleanup.
		private:
			std::vector<GameState*> stack; // Stack of states currently in use.
			Window* window; // The game's window.
	};
};
