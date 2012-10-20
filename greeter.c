#include "ruby.h"

VALUE greeter_say_it(VALUE self, VALUE name) {
  VALUE str = rb_str_new2("Hello, ");
  return rb_str_concat(str, name);
}

VALUE fixnum_reverse(VALUE self) {
  ID to_s = rb_intern("to_s");
  VALUE str = rb_funcall(self, to_s, 0);
  // 1.to_s
  ID reverse = rb_intern("reverse");
  str = rb_funcall(str, reverse, 0);
  // 1.to_s.reverse
  ID to_i = rb_intern("to_i");
  return rb_funcall(str, to_i, 0);
  // 1.to_s.reverse.to_i
}

void Init_greeter() {
  VALUE rb_cGreeter = rb_define_class("Greeter", rb_cObject);
  rb_define_method(rb_cGreeter, "say_it", greeter_say_it, 1);
  rb_define_method(rb_cFixnum, "reverse", fixnum_reverse, 0);
}

// make
// irb -I. -rgreeter
// > g = Greeter.new
// > g.say_it "GuruPI"
// > 123.reverse
