#include <chrono>

/**
 * @title getTime
 * @docs documents/gettime.md
 */

long long getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
