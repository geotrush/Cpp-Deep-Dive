/*
Task
You should define a struct for which the following would be possible:
int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
*/

struct Incognizable {
	int x = 0, y = 1; // Any pair of integers is possible
};
