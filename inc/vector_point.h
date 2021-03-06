/**
 * @file pointvector.h
 * @author Carlo Fornari and Jean Fontena
 * @date 21 may 2018
 *
 * @brief Code to define a dynamic vector to store xy coordinate points defined
 * by the struct Point.
 *
 *
 * @see Point
 */

#ifndef VECTORPOINT_H
#define VECTORPOINT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "inc/point.h"

#define VECTOR_POINT_DEFAULT_CAPACITY 4

/**
 * @brief Definition of VectorInt type.
 *
 * This is a dynamic vector. Initial capcaity is determined by the macro
 * @p VECTOR_POINT_DEFAULT_CAPACITY.
 */
typedef struct VectorPoint
{
  /** Number of slots used so far. */
  uint16_t length;

  /** Total quantity of slots available.*/
  uint16_t capacity;

  /** Array of integers for data. */
  Point *data;

  Point max;
  Point min;

} VectorPoint;


/**
 * @brief Inserts value at the end of the vector.
 *
 * If the underlying data array is full, then calling this function
 * should cause @p vector->data to expand to accept this value.
 *
 * Increments @p vector->size.
 *
 * @param value[in]
 * @param vector[out]
 */
void VectorPointAppend(const Point *value, VectorPoint *vector);
//===================================================================

/**
 * @brief Frees the memory allocated for the VectorPoint.
 *
 * Freeing the VectorPoint struct is left to client code (so it can
 * use any sort of pointer, be it stack or heap, and then clean up.
 *
 * @param vector[out] A pointer to the VectorPoint that should be destroyed.
 */
void DestroyVectorPoint(VectorPoint *vector);
//===================================================================

/**
 * @brief Initiate VectorInt struct.
 *
 * It sets @p vector->size to 0, capacity to @p VECTOR_POINT_DEFAULT_CAPACITY and
 * allocates an appropriate amount of memory (@p vector->capacity * sizeof(int))
 * for the underlying data array.
 *
 * @return A pointer to the VectorPoint created.
 */
VectorPoint *NewVectorPoint();
//===================================================================

/**
 * @brief Inserts @p value at the given @p index.
 *
 * If the index is greater than the @p vector->size, this function should
 * expand the vector until it is big enough to contain the @p index and set
 * the value at that @p index. It should zero-fill all values in between.
 * @p vector->size should be incremented accordingly.
 *
 * @param index[in]
 * @param value[in]
 * @param vector[out]
 */
void VectorPointInsert(const uint16_t index,
                       const Point *value,
                       VectorPoint *vector);
//===================================================================

/**
 * @brief Returns the number of points in the vector.
 * @param vector[in]
 * @return The number of slots used so far in the vector.
 */
uint16_t VectorPointGetSize(const VectorPoint *vector);
//===================================================================

/**
 * @brief Returns a Point inside VectorPoint at @p index position.
 *
 * Should be used when the client just wants Point's value.
 * If Point's value will be modified, VectorPointValueRef() should be
 * used instead.
 *
 * This function will throw an error message and exit the code if
 * @p index >= @p vector->size || @p index < 0.
 *
 * @param index[in]
 * @param vector[in]
 * @return The value of some Point inside Line.
 */

Point VectorPointGetValue(const int index, const VectorPoint *vector);
//===================================================================

/**
 * @brief Returns a reference to a Point inside VectorPoint at @p index position.
 *
 * Should be used when the client wants to modify Point's value.
 * If Point's value will NOT be modified, VectorPointValue() should be
 * used instead.
 *
 * This function will throw an error message and exit the code if
 * @p index >= @p vector->size || @p index < 0.
 *
 * @param index[in]
 * @param vector[in]
 * @return The address of some Point inside VectorPoint.
 */
Point *VectorPointValueRef(const int index, const VectorPoint *vector);
//===================================================================

/**
 * @brief VectorPointRemoveLastPoint
 * @param vector
 */
void VectorPointRemoveLastPoint(VectorPoint *vector);
//===================================================================

/**
 * @brief VectorPointReset
 * @param vector
 */
void VectorPointReset(VectorPoint *vector);
//===================================================================

#endif // VECTORPOINT_H
