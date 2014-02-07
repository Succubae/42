t_sort  *ft_separate(t_sort *start, t_sort *end, t_sort **newstart, t_sort **newend)
{
    t_sort  *middle;
    t_sort  *prev;
    t_sort  *current;
    t_sort  *last;

    middle = end;
    prev = NULL;
    current = start;
    last = middle;
    while (current != middle)
    {
        if (current->val < middle->val)
        {
            if ((*newstart) == NULL)
                (*newstart) = current;
            prev = current;
            current = current->next;
        }
        else
            ft_move_to_last(&current, &last, &prev);
    }
    if ((*newstart) == NULL)
        (*newstart) = middle;
    (*newend) = last;
    return (middle);
}
