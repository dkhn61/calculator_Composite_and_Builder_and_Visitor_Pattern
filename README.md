The design of the tree expression evaluator is based on three Design patterns:- Composite, Builder and the Visitor Design Pattern.
Using the accept method to visit the Binary(Operator) nodes and then saving the result in a visitor's state. The Visit method of operator node visits left node, then visits right node, then performs the operation. The toggle between visit and accept happens until the leaf (number) node is reached.

The expression evaluator is able to handle the following operators/tokens: +, -, /, *, %, (, ), integers (positive and negative). All expression will have a space between each token to simplify parsing. All input comes from the STDIN. The program loops until the user types QUIT. All output goes to STDOUT.
