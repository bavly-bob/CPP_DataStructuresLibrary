src/ contains the implementation files (.cpp) for non-template classes or functions.

For template classes like Stack<T>, you cannot compile them separately, so their implementation usually lives in .tpp files and is included in the headers (.h).