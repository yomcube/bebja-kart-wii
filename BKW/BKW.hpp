#pragma once

#include <PulsarSystem.hpp>
#include <BKWCommon.hpp>

namespace BKW {
	
class BKWPack : public Pulsar::System {
public:
    static Pulsar::System *Create(); //My Create function, needs to return a ptr to a Pulsar::System
    static BKWPack *GetInstance() { return static_cast<BKWPack*>(sInstance); } //for ease of use, optional
	void AfterInit() override;
};

} // namespace BKW