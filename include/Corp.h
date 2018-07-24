//
// Created by byzilio on 23.07.18.
//

#ifndef LABYRINTH_CORP_H
#define LABYRINTH_CORP_H

class Corp {
 protected:
  class Iterator{
   public:
    virtual bool hasNext() = 0;

    virtual Corp next() = 0;

    virtual void remove() = 0;
  };
 public:
  virtual void add(Corp *corp) = 0;

  virtual void addAll(Corp *corp) = 0;

  virtual void clear() = 0;

  virtual bool contains(Corp *corp) = 0;

  virtual bool isEmpty() = 0;

  virtual int size() = 0;

  virtual void remove(Corp *corp) = 0;

  virtual Iterator& iterator() = 0;

  /*
   * Или коллекции делать отдельными классами.
   * А как от итератора избавиться?
   */

  /*
   * Проблема в знание родителя из других Corp которые содержаться внутри.
   * Так как Corp может содержаться в нескольких других Corp.
   */

  /* А надо ли?
   * Corp *parent;
   * Когда добавляем другие части в коллекцию. Надо добавлять в parent добавляемого часть в которую добавляем.
   */

  virtual void function() = 0;
};

#endif  // LABYRINTH_CORP_H
