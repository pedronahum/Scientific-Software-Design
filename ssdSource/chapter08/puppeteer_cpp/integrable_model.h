/*
 * Copyright (c) 2011, Damian Rouson, Jim Xia, and Xiaofeng Xu.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Damian Rouson, Jim Xia, and Xiaofeng Xu nor the
 *       names of any other contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL DAMIAN ROUSON, JIM XIA, and XIAOFENG XU BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _H_INTEGRABLE_MODEL_
#define _H_INTEGRABLE_MODEL_

#include "mat.h"
#include "RefBase.h"

class integrable_model : virtual public RefBase {
public:
  typedef Ref<integrable_model> ptr_t;

  integrable_model();
  integrable_model(const integrable_model&);
  virtual ~integrable_model();

  // The following methods do dynamic allocation (yuck).
  virtual ptr_t d_dt() const = 0;
  virtual void  dRHS_dV(mat_t &result) const  = 0;
  virtual ptr_t clone() const = 0;
  virtual ptr_t  inverse_times(const mat_t&) const = 0;
  virtual crd_t state_vector() const = 0;
 
  // The following methods are destructive updates.
   virtual ptr_t operator+=(ptr_t) = 0;
  virtual ptr_t operator-=(ptr_t) = 0;
  virtual ptr_t operator*=(real_t) = 0;
};

// Integration routine.
void integrate(integrable_model::ptr_t state, double dt);

#endif //!_H_INTEGRABLE_MODEL_
