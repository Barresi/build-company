#pragma once

#include <string>

// Перечисление статусов проекта
enum class ProjectStatus {
    PLANNING,
    IN_PROGRESS,
    SUSPENDED,
    COMPLETED,
    CANCELLED
};

// Перечисление типов объектов
enum class ObjectType {
    RESIDENTIAL,
    INDUSTRIAL,
    COMMERCIAL,
    INFRASTRUCTURE
};

// Перечисление должностей персонала
enum class StaffRank {
    WORKER,
    FOREMAN,
    SITE_MANAGER,
    ENGINEER,
    PROJECT_DIRECTOR
};

// Перечисление специализаций персонала
enum class StaffSpecialization {
    MASON,
    WELDER,
    ELECTRICIAN,
    CRANE_OPERATOR,
    CONCRETE_WORKER,
    CARPENTER,
    PLUMBER,
    GENERAL
};

// Перечисление единиц измерения для сыпучих материалов
enum class MeasureType {
    PIECES,
    KILOGRAMS,
    CUBIC_METERS,
    SQUARE_METERS,
    TONS
};

// Перечисление типов инструментов
enum class ToolType {
    POWER_DRILL,
    HAMMER_DRILL,
    SCREWDRIVER,
    ANGLE_GRINDER,
    CIRCULAR_SAW,
    WELDING_MACHINE,
    HAND_TOOL
};

// Перечисление типов транспортных средств
enum class VehicleType {
    EXCAVATOR,
    BULLDOZER,
    CRANE,
    DUMP_TRUCK,
    CONCRETE_MIXER,
    LOADER,
    GRADER,
    ASPHALT_PAVER
};

// Перечисление типов топлива
enum class FuelType {
    DIESEL,
    GASOLINE,
    ELECTRIC,
    HYBRID
};

// Вспомогательные функции для преобразования перечислений в строки
inline std::string projectStatusToString(ProjectStatus status) {
    switch (status) {
        case ProjectStatus::PLANNING: return "Planning";
        case ProjectStatus::IN_PROGRESS: return "In Progress";
        case ProjectStatus::SUSPENDED: return "Suspended";
        case ProjectStatus::COMPLETED: return "Completed";
        case ProjectStatus::CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

inline std::string objectTypeToString(ObjectType type) {
    switch (type) {
        case ObjectType::RESIDENTIAL: return "Residential";
        case ObjectType::INDUSTRIAL: return "Industrial";
        case ObjectType::COMMERCIAL: return "Commercial";
        case ObjectType::INFRASTRUCTURE: return "Infrastructure";
        default: return "Unknown";
    }
}

inline std::string staffRankToString(StaffRank rank) {
    switch (rank) {
        case StaffRank::WORKER: return "Worker";
        case StaffRank::FOREMAN: return "Foreman";
        case StaffRank::SITE_MANAGER: return "Site Manager";
        case StaffRank::ENGINEER: return "Engineer";
        case StaffRank::PROJECT_DIRECTOR: return "Project Director";
        default: return "Unknown";
    }
}

inline std::string staffSpecializationToString(StaffSpecialization spec) {
    switch (spec) {
        case StaffSpecialization::MASON: return "Mason";
        case StaffSpecialization::WELDER: return "Welder";
        case StaffSpecialization::ELECTRICIAN: return "Electrician";
        case StaffSpecialization::CRANE_OPERATOR: return "Crane Operator";
        case StaffSpecialization::CONCRETE_WORKER: return "Concrete Worker";
        case StaffSpecialization::CARPENTER: return "Carpenter";
        case StaffSpecialization::PLUMBER: return "Plumber";
        case StaffSpecialization::GENERAL: return "General";
        default: return "Unknown";
    }
}

inline std::string measureTypeToString(MeasureType type) {
    switch (type) {
        case MeasureType::PIECES: return "pcs";
        case MeasureType::KILOGRAMS: return "kg";
        case MeasureType::CUBIC_METERS: return "m3";
        case MeasureType::SQUARE_METERS: return "m2";
        case MeasureType::TONS: return "t";
        default: return "Unknown";
    }
}

inline std::string toolTypeToString(ToolType type) {
    switch (type) {
        case ToolType::POWER_DRILL: return "Power Drill";
        case ToolType::HAMMER_DRILL: return "Hammer Drill";
        case ToolType::SCREWDRIVER: return "Screwdriver";
        case ToolType::ANGLE_GRINDER: return "Angle Grinder";
        case ToolType::CIRCULAR_SAW: return "Circular Saw";
        case ToolType::WELDING_MACHINE: return "Welding Machine";
        case ToolType::HAND_TOOL: return "Hand Tool";
        default: return "Unknown";
    }
}

inline std::string vehicleTypeToString(VehicleType type) {
    switch (type) {
        case VehicleType::EXCAVATOR: return "Excavator";
        case VehicleType::BULLDOZER: return "Bulldozer";
        case VehicleType::CRANE: return "Crane";
        case VehicleType::DUMP_TRUCK: return "Dump Truck";
        case VehicleType::CONCRETE_MIXER: return "Concrete Mixer";
        case VehicleType::LOADER: return "Loader";
        case VehicleType::GRADER: return "Grader";
        case VehicleType::ASPHALT_PAVER: return "Asphalt Paver";
        default: return "Unknown";
    }
}

inline std::string fuelTypeToString(FuelType type) {
    switch (type) {
        case FuelType::DIESEL: return "Diesel";
        case FuelType::GASOLINE: return "Gasoline";
        case FuelType::ELECTRIC: return "Electric";
        case FuelType::HYBRID: return "Hybrid";
        default: return "Unknown";
    }
}
