#pragma once

class Feature {
public:
    virtual ~Feature() = default;
    virtual void update(bool menuOpen) = 0;
    virtual const char* getName() const = 0;
};
