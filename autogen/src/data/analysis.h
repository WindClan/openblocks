#pragma once

#include <clang-c/Index.h>
#include <map>
#include <string>
#include <vector>

namespace data {

enum PropertyBackingType {
    Method,
    Field
};

struct PropertyAnalysis {
    std::string name;
    std::string backingSymbol;
    PropertyBackingType backingType;
    std::string valueType;
};

struct OperatorAnalysis {
    std::string type;
    std::string param_type;
};

struct MethodParameter {
    std::string name;
    std::string type;
};

struct MethodAnalysis {
    std::string name;
    std::string functionName;
    std::string returnType;
    std::vector<MethodParameter> parameters;
};

struct ClassAnalysis {
    std::string name;
    std::string serializedName;
    std::string headerPath;
    bool hasFromString;
    bool isSerializable;
    bool hasGenericDeserializer;
    bool hasGenericFromString;
    std::vector<PropertyAnalysis> properties;
    std::vector<MethodAnalysis> methods;
    std::vector<PropertyAnalysis> staticProperties;
    std::vector<MethodAnalysis> staticMethods;
    std::map<std::string, std::vector<OperatorAnalysis>> operators;
};

struct AnalysisState {
    std::map<std::string, ClassAnalysis> classes;
};

bool analyzeClasses(CXCursor cursor, std::string srcRoot, AnalysisState* state);

}