template<class Object>
int MTFList<Object>::find( const Object &obj ) {
  DListNode<Object> *found = DList<Object>::header->next;

  int i = 0;
  for ( ; found != NULL && found->item != obj;  found = found->next, ++i )
    ++DList<Object>::cost;

  if ( found == NULL )
    return -1; // not found

  if ( found == DList<Object>::header->next )
    return 0;  // no need to swap

  // remove found from the current position
  DListNode<Object> *prev = found->prev;
  prev->next = found->next;               // found->prev != null
  if ( found->next != NULL )
    found->next->prev = found->prev;

  // insert found in front of list

  DList<Object>::header->next->prev = found;
  found->next = DList<Object>::header->next;
  found->prev = DList<Object>::header;
  DList<Object>::header->next = found;

  return i;
}



