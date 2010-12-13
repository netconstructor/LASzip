/******************************************************************************
 *
 * Project:  integrating laszip into liblas - http://liblas.org -
 * Purpose:
 * Author:   Martin Isenburg
 *           isenburg at cs.unc.edu
 *
 ******************************************************************************
 * Copyright (c) 2010, Martin Isenburg
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Licence as published
 * by the Free Software Foundation.
 *
 * See the COPYING file for more information.
 *
 ****************************************************************************/

/*
===============================================================================

  FILE:  LASzipper.hpp
  
  CONTENTS:
  
    Writes (optionally compressed) LIDAR points to LAS formats 1.0 - 1.3

  PROGRAMMERS:
  
    martin isenburg@cs.unc.edu
  
  COPYRIGHT:
  
    copyright (C) 2010  martin isenburg@cs.unc.edu
    
    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    12 December 2010 -- created from LASwriter/LASreader after Howard got pushy (-;
  
===============================================================================
*/
#ifndef LAS_ZIPPER_H
#define LAS_ZIPPER_H

#include <ostream.h>

#include "laszip.hpp"

class ByteStreamOut;
class LASwritePoint;

class LASzipper
{
public:

  bool open(ostream* ostream, unsigned int num_items, LASitem* items, unsigned int compression=0);
  bool write(unsigned char** point);
  bool chunk(LASchunk* chunk);
  bool close(LASchunk* chunk=0);

  LASzipper();
  ~LASzipper();

private:
  int count;
  ByteStreamOut* stream;
  LASwritePoint* writer;
};

#endif