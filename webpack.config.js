const path = require('path');

module.exports = {
  resolve: {
    modules: [
      path.resolve(__dirname, "src"),
      path.resolve(__dirname, "lib/js/src"),
      "node_modules"
    ]
  },
  entry: {
      reason: [
        './src/interop.js',
        './lib/js/src/examples4.js',
        './lib/js/src/square.js',
        './lib/js/src/main.js',
      ]
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
