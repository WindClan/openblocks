#pragma once

#include "objects/annotation.h"
#include "objects/base/instance.h"
#include "objects/joint/jointinstance.h"
#include <memory>

namespace reactphysics3d { class FixedJoint; }

class DEF_INST Weld : public JointInstance {
    AUTOGEN_PREAMBLE

    reactphysics3d::FixedJoint* joint = nullptr;

    virtual void buildJoint() override;
    virtual void breakJoint() override;
public:
    Weld();
    ~Weld();

    static inline std::shared_ptr<Weld> New() { return std::make_shared<Weld>(); };
    static inline std::shared_ptr<Instance> Create() { return std::make_shared<Weld>(); };
};