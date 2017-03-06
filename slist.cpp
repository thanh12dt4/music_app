#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"
#include <QDebug>
/*!
 * \brief Append an item to single link list
 * \param[in] list input single link list
 * \param[in] data pointer to data of appended item.
 * \return #slist the list after append
 */
extern slist * slist_append(slist * list, void * data) {
    slist* new_list = (slist*) malloc (sizeof (slist));
    slist* out_list = list;
    new_list->data = data;
    new_list->next = NULL;
    new_list->previous = NULL;

    if (list == NULL) {
        list = new_list;
        return list;
    }
    else {
        while (list->next != NULL) {
            list = list->next;
        }
        list->next = new_list;
        new_list->previous = list;
    }
    return out_list;
}

/*!
 * \brief Remove all item of list, release data of all item.
 * \param[in] list input single link list
 * \param[in] release_data callback function to release data of removed items.
 * \return #slist the list after delete
 */

extern slist * slist_delete_all_x(slist * list, void (*release_data)(void *data)) {
    slist* walk = list;
    while (walk) {
        walk = list;
        list = list->next;
        if (release_data) {
            release_data ((void*)walk->data);
        }
        free (walk);
        walk = list;
    }
    return NULL;
}

/*!
 * \brief Find an item in a single link list with  condition.
 * \param[in] list input single link list will be find
 * \param[in] data input data condition.
 * \param[in] compare_func callback function to compare data of an item with condition data.
 * \return #slist the found item.
 */
extern slist * slist_find(slist * list, void * data, bool (*compare_func)(void * data1, void * data2)) {
    slist* walk = list;
    size_t index = 0;
    while (walk) {
        if (compare_func) {
            if (compare_func ((void*) walk->data, data)) {
                return walk;
            }
        }
        walk =  walk->next;
        index++;
    }
    return NULL;
}
