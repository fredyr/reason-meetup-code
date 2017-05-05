
/// Exporting a function so that we can call it from Reason

export function incBy3(x) {
    return x + 3;
}



/// Calling a Reason function from Javascript

import {decBy2} from 'examples5';
console.log("From Javascript:", decBy2(9));
