#include "tap.h"

void sub_test(tap_t* t) {
  // Tell the document to expect a certain number of checks
  tap_plan(t, 6);

  // Can check that a given value is truthy
  tap_ok(t, true, "value is truthy");

  // Checks can be skipped with an optional explanation
  tap_skip(t, "Next check would fail");

  // Can check that a given value is falsy
  tap_not_ok(t, true, "value is falsy");

  // Mark an always passing test, useful in if/else branches
  tap_pass(t, "awyiss");

  // Multiple checks can be skipped with an optional explanation for each
  tap_skip_n(t, 1, "Next check would fail");

  // Mark an always failing test, useful in if/else branches
  tap_fail(t, "Oh no!");

  // Check equality, any type that works with == will work
  tap_equal(t, 1, 1, "equal");

  // Check inequality, any type that works with != will work
  tap_not_equal(t, 1, 2, "not equal");
}

void test(tap_t* t) {
  // Comment lines can help separate related checks in a flatter and simpler
  // way than sub-tests which will indent at each level
  tap_comment(t, "some comment");

  // Sub-tests can have their own sub-tests, go as deep as you need!
  tap_test(t, "sub", sub_test);
}

int main() {
  // Construct a TAP document writing to stdout
  tap_t t = tap(stdout);

  // Turn on pragma strict
  tap_on(&t, "strict");

  // Turn off pragma bail
  tap_off(&t, "bail");

  // Sub-tests can group many related checks. Also accepts a pointer after the
  // test function to store at t->data.
  tap_test(&t, "foo", test);

  // Checks can be used at the top-level too if you don't need sub-tests
  tap_pass(&t, "top-level check");

  // You can bail out at any time and the proces will exit
  tap_bail_out(&t, "just bailing for no reason");

  // Ending the TAP document will return 0 if all checks passed.
  // If there were failures or plan count did not match it will return 1.
  // This is handy as a return code.
  return tap_end(&t);
}
