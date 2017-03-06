#ifndef SLIST_H_
#define SLIST_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slist{
    void * data;  /**< the pointer to data */
    struct slist * next;  /**< the pointer to next element of list */
    struct slist *previous; /**< the pointer to previous element of list */
}slist;

#define FORCE_DATA_TYPE(type,item) ((type*)(item->data))

typedef void (*release_data_function)(void*);
typedef bool (*compare_function)(void*,void*);
typedef void (*trace_function)(int , void*);

/*!
 * \brief Append an item to single link list
 * \param[in] list input single link list
 * \param[in] data pointer to data of appended item.
 * \return #slist the list after append
 */
extern slist * slist_append(slist * list, void * data);

/*!
 * \brief Remove all item of list, release data of all item.
 * \param[in] list input single link list
 * \param[in] release_data callback function to release data of removed items.
 * \return #slist the list after delete
 */

extern slist * slist_delete_all_x(slist * list, void (*release_data)(void *data));

/*!
 * \brief Find an item in a single link list with  condition.
 * \param[in] list input single link list will be find
 * \param[in] data input data condition.
 * \param[in] compare_func callback function to compare data of an item with condition data.
 * \return #slist the found item.
 */
extern slist * slist_find(slist * list, void * data, bool (*compare_func)(void * data1, void * data2));

#ifdef __cplusplus
}
#endif
#endif /* SLIST_H_ */
