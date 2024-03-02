#include <stdio.h>
#include <string.h>

// Define your functions here
void pa() {
    printf("pa function called\n");
}

void pb() {
    printf("pb function called\n");
}

void rrr() {
    printf("rrr function called\n");
}

// Create a struct to hold the mapping between command names and functions
typedef struct {
    char *name;
    void (*func)();
} Command;

// Create a lookup table of commands
Command commands[] = {
    {"pa", pa},
    {"pb", pb},
    {"rrr", rrr},
    {NULL, NULL} // Sentinel to mark the end of the array
};

Command commands[4]; // Declare an array of 4 Command structures

void initialize_commands() {
    commands[0].name = "pa";
    commands[0].func = pa;

    commands[1].name = "pb";
    commands[1].func = pb;

    commands[2].name = "rrr";
    commands[2].func = rrr;

    commands[3].name = NULL;
    commands[3].func = NULL;
}

// Function to execute a command by name
void execute_command(char *name) {
    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(commands[i].name, name) == 0) {
            commands[i].func();
            return;
        }
    }
    printf("Unknown command: %s\n", name);
}

int main() {
    // Test the execute_command function
    execute_command("pa");
    execute_command("pb");
    execute_command("rrr");
    execute_command("unknown");
    return 0;
}