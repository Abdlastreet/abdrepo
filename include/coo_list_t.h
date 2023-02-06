/*
** EPITECH PROJECT, 2022
** storage_list
** File description:
** structure containing list of storages
*/
#include "storage_t.h"
#include "coordinates_t.h"
#ifndef COO_LIST_T_H_
    #define COO_LIST_T_H_
typedef struct storage_list_s {
    int nbstorage;
    storage_t *storage_list;
} storage_list_t;
#endif /* COO_LIST_T_H_ */
