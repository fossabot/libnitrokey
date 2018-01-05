/*
 * Copyright (c) 2015-2018 Nitrokey UG
 *
 * This file is part of Libnitrokey.
 *
 * Libnitrokey is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Libnitrokey is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Libnitrokey. If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: LGPL-3.0
 */

//
// Created by sz on 24.10.16.
//

#ifndef LIBNITROKEY_LONGOPERATIONINPROGRESSEXCEPTION_H
#define LIBNITROKEY_LONGOPERATIONINPROGRESSEXCEPTION_H

#include "CommandFailedException.h"

class LongOperationInProgressException : public CommandFailedException {

public:
    unsigned char progress_bar_value;

    LongOperationInProgressException(
        unsigned char _command_id, uint8_t last_command_status, unsigned char _progress_bar_value)
    : CommandFailedException(_command_id, last_command_status), progress_bar_value(_progress_bar_value){
      LOG(
          std::string("LongOperationInProgressException, progress bar status: ")+
              std::to_string(progress_bar_value), nitrokey::log::Loglevel::DEBUG);
    }
    virtual const char *what() const throw() {
      return "Device returned busy status with long operation in progress";
    }
};


#endif //LIBNITROKEY_LONGOPERATIONINPROGRESSEXCEPTION_H
