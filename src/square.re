/*
   A React component Square

   - Uses modules for the definition of a component and
     its lifecycle functions.
   - Takes an int as prop
   - In contrast to React w/ Javascript, your state and props
     needs to be defined by types
 */
module Square = {
  include ReactRe.Component;
  type props = {value: int};
  let name = "Square";
  /*
     All life cycle methods takes a `componentBag` record of shape
     {props, state, updater, handler, instanceVars, setState}

     - This avoids the use of `this`.
     - Normal record destructuring. Pick what you need.
   */
  let render {props} =>
    <div className="square"> (ReactRe.stringToElement (string_of_int props.value)) </div>;
};

include ReactRe.CreateComponent Square;

let createElement ::value => wrapProps {value: value};
/* ^ Note: there's no record field punning sugar for records with a single field. Careful! `{foo}` has a different meaning. */
