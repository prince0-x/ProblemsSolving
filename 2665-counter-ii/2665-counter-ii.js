/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    return {
        increment: function() {
            return ++val;
        },
        decrement: function() {
            return --val;
        },
        reset: function() {
            val = init;
            return val;
        }
    };
};
