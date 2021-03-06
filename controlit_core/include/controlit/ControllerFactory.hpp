/*
 * Copyright (C) 2015 The University of Texas at Austin and the
 * Institute of Human Machine Cognition. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 2.1 of
 * the License, or (at your option) any later version. See
 * <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 */

#ifndef __CONTROLIT_CONTROLLER_FACTORY__
#define __CONTROLIT_CONTROLLER_FACTORY__


// #include <memory>
// #include <list>

#include <ros/ros.h>
#include <pluginlib/class_loader.h>

#include <controlit/Controller.hpp>

namespace controlit {

/*!
 * Creates the whole body controller.
 */
class ControllerFactory
{
public:

    /*!
     * The constructor.
     *
     */
    ControllerFactory();

    /*!
     * The destructor.
     */
    ~ControllerFactory();

    /*!
     * Creates the whole body controller.
     *
     * \param[in] controllerName The name of the whole body controller. This 
     * must match the name of the plugin containing the controller.
     * \return A pointer to the newly-created controller or nullptr if it failed.
     */
    virtual Controller * createController(std::string controllerName);

private:

    /*!
     * The class loader that is used to create the Controller objects.
     */
    std::unique_ptr<pluginlib::ClassLoader<Controller>> classLoader;
};

} // namespace controlit

#endif // __CONTROLIT_CONTROLLER_FACTORY__
