#include <unistd.h>

int main() {
  int f1[2], f2[2];
  pipe(f1);
  pipe(f2);

  if (!fork()) {
    // Child
    dup2(STDIN_FILENO, f1[0]);
    dup2(STDOUT_FILENO, f2[1]);
    char *cmd = "./test";
    char *argv[2];
    argv[0] = "./test";
    argv[1] = NULL;

    execvp(cmd, argv);
  }

  if (!fork()) {
    // Child
    dup2(STDIN_FILENO, f2[0]);
    dup2(STDOUT_FILENO, f1[1]);
    char *cmd = "./iat";
    char *argv[2];
    argv[0] = "./iat";
    argv[1] = NULL;

    execvp(cmd, argv);
  }
}
