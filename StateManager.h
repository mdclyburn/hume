#include "GameState.h"
#include <vector>

namespace hm
{
	class StateManager // Handles the switching of states.
	{
		public:
			StateManager(); // Basic constructor.

			void resumeState(); // Restarts the state on the top of the stack.
			void pauseState(); // Pause the state at the top of the stack.

			void pushState(GameState& gs); // Adds a state to the stack.
			void popState(); // Pops a state from the stack.
			void replaceState(GameState& gs); // Switches out a state.
		private:
			std::vector<GameState*> stack; // Stack of states currently in use.
	};
};