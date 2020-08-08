#include "catch.hpp"
#include "input_event.h"
#include "input_type.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

TEST_CASE( "test input event" )
{
  InputType current;
  InputType previous;
  unique_ptr<InputEvent> event;

  SECTION( "test left up")
  {
    current = InputType::none;
    previous = InputType::left;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE( event -> left_up() );
    REQUIRE_FALSE( event -> right_up() );
    REQUIRE_FALSE( event -> down_up() );
    REQUIRE_FALSE( event -> enter_up() );
    REQUIRE_FALSE( event -> romeo_up() );
    REQUIRE_FALSE( event -> escape() );
  }

  SECTION( "test right up")
  {
    current = InputType::none;
    previous = InputType::right;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE_FALSE( event -> left_up() );
    REQUIRE( event -> right_up() );
    REQUIRE_FALSE( event -> down_up() );
    REQUIRE_FALSE( event -> enter_up() );
    REQUIRE_FALSE( event -> romeo_up() );
    REQUIRE_FALSE( event -> escape() );
  }

  SECTION( "test down up")
  {
    current = InputType::none;
    previous = InputType::down;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE_FALSE( event -> left_up() );
    REQUIRE_FALSE( event -> right_up() );
    REQUIRE( event -> down_up() );
    REQUIRE_FALSE( event -> enter_up() );
    REQUIRE_FALSE( event -> romeo_up() );
    REQUIRE_FALSE( event -> escape() );
  }

  SECTION( "test enter up")
  {
    current = InputType::none;
    previous = InputType::enter;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE_FALSE( event -> left_up() );
    REQUIRE_FALSE( event -> right_up() );
    REQUIRE_FALSE( event -> down_up() );
    REQUIRE( event -> enter_up() );
    REQUIRE_FALSE( event -> romeo_up() );
    REQUIRE_FALSE( event -> escape() );
  }

  SECTION( "test romeo up")
  {
    current = InputType::none;
    previous = InputType::romeo;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE_FALSE( event -> left_up() );
    REQUIRE_FALSE( event -> right_up() );
    REQUIRE_FALSE( event -> down_up() );
    REQUIRE_FALSE( event -> enter_up() );
    REQUIRE( event -> romeo_up() );
    REQUIRE_FALSE( event -> escape() );
  }

  SECTION( "test escape")
  {
    current = InputType::escape;
    previous = InputType::none;

    event = make_unique<InputEvent>( current, previous );
    REQUIRE_FALSE( event -> left_up() );
    REQUIRE_FALSE( event -> right_up() );
    REQUIRE_FALSE( event -> down_up() );
    REQUIRE_FALSE( event -> enter_up() );
    REQUIRE_FALSE( event -> romeo_up() );
    REQUIRE( event -> escape() );
  }
}
