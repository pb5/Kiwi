/*
 ==============================================================================
 
 This file is part of the KIWI library.
 - Copyright (c) 2014-2016, Pierre Guillot & Eliott Paris.
 - Copyright (c) 2016-2019, CICM, ANR MUSICOLL, Eliott Paris, Pierre Guillot, Jean Millot.
 
 Permission is granted to use this software under the terms of the GPL v3
 (or any later version). Details can be found at: www.gnu.org/licenses
 
 KIWI is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 
 ------------------------------------------------------------------------------
 
 Contact : cicm.mshparisnord@gmail.com
 
 ==============================================================================
 */

#include <KiwiModel/KiwiModel_Objects/KiwiModel_GreaterEqualTilde.h>
#include <KiwiModel/KiwiModel_Factory.h>

namespace kiwi { namespace model {
    
    // ================================================================================ //
    //                                  OBJECT >=~                                       //
    // ================================================================================ //
    
    void GreaterEqualTilde::declare()
    {
        if (!DataModel::has<model::OperatorTilde>())
        {
            OperatorTilde::declare();
        }
        
        std::unique_ptr<ObjectClass> greaterequal_class(new ObjectClass(">=~", &GreaterEqualTilde::create));
        
        flip::Class<GreaterEqualTilde> & greaterequal_model = DataModel::declare<GreaterEqualTilde>()
                                                                .name(greaterequal_class->getModelName().c_str())
                                                                .inherit<OperatorTilde>();
        
        Factory::add<GreaterEqualTilde>(std::move(greaterequal_class), greaterequal_model);
    }
    
    std::unique_ptr<Object> GreaterEqualTilde::create(std::vector<tool::Atom> const& args)
    {
        return std::make_unique<GreaterEqualTilde>(args);
    }
    
    GreaterEqualTilde::GreaterEqualTilde(std::vector<tool::Atom> const& args):
    OperatorTilde(args)
    {
    }
    
}}
