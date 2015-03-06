# calculator 
This is a simple calculator app.

NOTES:

  * You can download a zipped archive from the link on the right side of the repository page
  * A binary precompiled file (Ubuntu 12.04 LTS, x86_64) can be found in:
    - bin/qtcreator/release/app/calc
  * the build is a x64_64 and NOT 32 bit one.
  * the build has been generated with QtCreator (without Qt dependencies)
  * the calculator supports a single root expression,
    meaning: 3+3+3 will not be parsed, but (3+3)+3 will
    (as (3+3) is a single expression which will be evaluated to a term)
  * the calculator returns 0 in case of errors
  * the test cases are in the test sub-folder
