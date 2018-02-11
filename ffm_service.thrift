struct Node {
  1: i32 field = 0,
  2: i32 feature = 1,
  3: double value = 2
}

service FFMPredictor {
  void ping(),
  double predict( 1: list<Node> features )
}
