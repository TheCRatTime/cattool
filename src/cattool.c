/*
 * Copyright (C) 2026 TheCRatTime
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE ((1024 * 1024 * 10) - 1)

int main(int argc, char** argv) {
  char buffer[BUFFER_SIZE+1];

  if (argc < 2) {
    printf("Usage: %s: [FILES...]\n", argv[0]);
    return 1;
  }

  argv++;

  while(*argv != NULL) {
    FILE* file = fopen(*argv, "rb");
    if (file == NULL) {
      perror(argv[0]);
      argv++;
      continue;
    }

    while(fread(buffer, 1, BUFFER_SIZE, file) > 0) {
      buffer[BUFFER_SIZE] = '\0';
      printf("%s", buffer);
    }
    
    fclose(file);
    
    argv++;
  }

  putchar('\n');
  return 0;
}
