# tapsy

Tapsy is a single-header TAP test framework for C or C++. It avoids taking over
the process, leaving it to the user to handle the setup, which enables running
in weird environments like inside a Node.js native module.

See [example.c](example.c) and [example.cc](example.cc) for how to use it.

Documentation can also be generated with `make docs`.
