#pragma once

#include "objects/annotation.h"
#include "objects/base/instance.h"
#include "objects/joint/jointinstance.h"
#include <memory>

namespace reactphysics3d { class HingeJoint; }

class DEF_INST Rotate : public JointInstance {
    AUTOGEN_PREAMBLE

    reactphysics3d::HingeJoint* joint = nullptr;

    virtual void buildJoint() override;
    virtual void breakJoint() override;
public:
    Rotate();
    ~Rotate();

    static inline std::shared_ptr<Rotate> New() { return std::make_shared<Rotate>(); };
    static inline std::shared_ptr<Instance> Create() { return std::make_shared<Rotate>(); };
};