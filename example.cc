#include "tap.h"

void sub_test(Tap& t) {
  // Tell the document to expect a certain number of checks
  t.plan(6);

  // Can check that a given value is truthy
  t.ok(true, "value is truthy");

  // Checks can be skipped with an optional explanation
  t.skip("Next check would fail");

  // Can check that a given value is falsy
  t.not_ok(true, "value is falsy");

  // Mark an always passing test, useful in if/else branches
  t.pass("awyiss");

  // Multiple checks can be skipped with an optional explanation for each
  t.skip(1, "Next check would fail");

  // Mark an always failing test, useful in if/else branches
  t.fail("Oh no!");

  // Check equality, any type that works with == will work
  t.equal(1, 1, "yep");

  // Check inequality, any type that works with != will work
  t.not_equal(1, 2, "nope");
}

void test(Tap& t) {
  // Comment lines can help separate related checks in a flatter and simpler
  // way than sub-tests which will indent at each level
  t.comment("some comment");

  // Sub-tests can have their own sub-tests, go as deep as you need!
  t.test("sub", sub_test);
}

int main() {
  // Construct a TAP document writing to stdout
  Tap t(stdout);

  // Turn on pragma strict
  t.on("strict");

  // Turn off pragma bail
  t.off("bail");

  // Sub-tests can group many related checks. Also supports capturing lambdas!
  t.test("foo", test);

  // Checks can be used at the top-level too if you don't need sub-tests
  t.pass("top-level check");

  // You can bail out at any time and the proces will exit
  t.bail_out("just bailing for no reason");

  // Ending the TAP document will return 0 if all checks passed.
  // If there were failures or plan count did not match it will return 1.
  // This is handy as a return code.
  return t.end();
}
