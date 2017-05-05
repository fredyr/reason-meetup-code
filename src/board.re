module Board = {
  include ReactRe.Component.Stateful;
  /* Unit is similar to void, we're not using props */
  type props = unit;
  type state = {squares: array int};
  let name = "Board";
  let getInitialState _ => {squares: [|0, 0, 0, 0, 0, 0, 0, 0, 0|]};
  let updateCounter ::index {state} event => {
    state.squares.(index) = state.squares.(index) + 1;
    Some state
  };
  /* updater takes in your familiar callback and returns a new (memoized)
     callback that'll give you the up-to-date "component bag" (props, state and
     other values) when the callback is called, and ensures that the component
     state is appropriately updated after the callback */
  let render {state, updater} => {
    let renderSquare i =>
      <div onClick=(updater (updateCounter index::i))> <Square value=state.squares.(i) /> </div>;
    <div>
      <div className="board-row"> (renderSquare 0) (renderSquare 1) (renderSquare 2) </div>
      <div className="board-row"> (renderSquare 3) (renderSquare 4) (renderSquare 5) </div>
      <div className="board-row"> (renderSquare 6) (renderSquare 7) (renderSquare 8) </div>
    </div>
  };
};

include ReactRe.CreateComponent Board;

let createElement = wrapProps ();
/*
  Re-using already written React Components in Javascript is almost as simple
  as the interop itself.

  Provide a createElement function that maps your Reason types to the corresponding
  Javascript tags and you're good to go.

  Example from the docs

  external foo : ReactRe.reactClass = "Banner" [@@bs.module];

  This is the call that takes in Reason data and converts it to JS data.

  let createElement
    className::(className: option string)=?
    show::(show: bool) =>
  ReactRe.wrapPropsShamelessly
    foo
    {
      "className": Js.Null_undefined.from_opt className,
      "show": Js.Bool.to_js_boolean show,
    };


   Or use a Reason/React component from Javascript with

   var MyReasonComponent = require('myReasonComponent').comp;
   <MyReasonComponent message="hello" />


 */
