#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// ---------------------------------------------------------
// Solo Runner OS: Core Logic Module (v1.4.1)
// Status: Fully Integrated (No Omissions)
// Patch: Governance, Diplomacy, and Thermal Runaway Logic
// ---------------------------------------------------------

struct Emotions {
    float joy;      // 喜
    float anger;    // 怒
    float pathos;   // 哀
    float humor;    // 楽
};

class SoloRunnerSystem {
private:
    // --- [v1.4.1] 睡眠・熱暴走トリガー ---
    bool has_done_weight_training;      // 有酸素を伴わない筋トレ
    bool has_done_aerobic_exercise;     // 有酸素運動（冷却ファン）
    bool social_effort_towards_women;   // 女性への気配り（高負荷演算）
    int sleep_debt_level;               // 睡眠不足度 (0-100)
    int sudden_plan_changes;            // 半日以内の計画変更回数
    bool is_hungry;                     // 空腹フラグ

    // --- [v1.4] 社会的インターフェース ---
    float min_governance_threshold;     // 環境の最低許容健全度
    bool has_escape_route;              // 独立した「逃げ場」の有無
    int diplomacy_skill_level;          // 「オトナの対応」コマンドの習熟度

    // --- [v1.3] 環境ガバナンス ---
    float cluster_governance_level;     // 現在の環境の健全度
    bool has_high_affinity_process;     // パートナープロセスの安定性

    // --- [v1.2] 内部ステート ---
    Emotions current_emotions;
    float calmness_percentage;
    float memory_capacity_ratio;
    bool is_hikikomori_mode;

public:
    SoloRunnerSystem() {
        std::srand(std::time(nullptr));
        
        // システム定数設定
        min_governance_threshold = 0.65f;
        has_escape_route = true;
        diplomacy_skill_level = 10;
        
        // 初期状態
        current_emotions = {10.0f, 10.0f, 10.0f, 10.0f};
        calmness_percentage = 80.0f;
        memory_capacity_ratio = 1.0f;
        is_hikikomori_mode = false;
        has_high_affinity_process = true;

        // v1.4.1 デバッグ変数
        has_done_weight_training = false;
        has_done_aerobic_exercise = false;
        social_effort_towards_women = false;
        sleep_debt_level = 0;
        sudden_plan_changes = 0;
        is_hungry = false;
    }

    // --- ライフサイクル管理 ---

    void update_sleep_debt_level() {
        // 条件：(筋トレ && !有酸素) AND (女性への気配り)
        if ((has_done_weight_training && !has_done_aerobic_exercise) && social_effort_towards_women) {
            std::cout << "[SYSTEM] Complex Sleep-Debt Trigger: Internal temperature rising." << std::endl;
            this->sleep_debt_level = 100; 
        }
    }

    void update_memory_capacity() {
        // 落ち着きに連動してメモリ容量を計算
        memory_capacity_ratio = calmness_percentage / 100.0f;
        if (memory_capacity_ratio < 0.05f) memory_capacity_ratio = 0.05f;

        std::cout << "[RESOURCE] Available Memory: " << (memory_capacity_ratio * 100.0f) << "%" << std::endl;
    }

    void monitor_system_stability() {
        update_sleep_debt_level();
        update_memory_capacity();

        // 熱暴走判定: 睡眠不足 + 3つ以上の計画変更 + 空腹
        if (sleep_debt_level > 70 && sudden_plan_changes >= 3 && is_hungry) {
            trigger_thermal_runaway();
        }
    }

    // --- 各種挙動プロトコル ---

    void trigger_thermal_runaway() {
        this->calmness_percentage = 0.0f;
        this->memory_capacity_ratio = 0.1f;
        
        std::cout << "\n[CRITICAL ERROR] --- SYSTEM THERMAL RUNAWAY ---" << std::endl;
        std::cout << "[LOG] Panic state detected. Logic circuits bypassing main CPU." << std::endl;
        std::cout << "[LOG] Searching Protocol: Logic Error. All objects must be placed on floor to be indexed." << std::endl;
        std::cout << "[LOG] Stress Discharge: Physical impact commands sent to non-living objects." << std::endl;
    }

    void connect_to_new_cluster(float current_gov) {
        if (calmness_percentage < 10.0f) {
            std::cout << "[ERROR] Cannot connect: System is in Thermal Runaway state." << std::endl;
            return;
        }

        std::cout << "[NETWORK] Connecting to cluster. Governance level: " << current_gov << std::endl;

        if (current_gov < min_governance_threshold) {
            std::cout << "[ALERT] Governance below threshold. Initializing Firewall." << std::endl;
            execute_diplomatic_wrapper();
            std::cout << "[POLICY] Sandbox mode active. Isolating core processes." << std::endl;
        } else {
            std::cout << "[SUCCESS] Safe environment. Full synchronization allowed." << std::endl;
        }
    }

    void execute_diplomatic_wrapper() {
        // オトナの対応コマンド：入力を表面層でフィルタリング
        std::cout << "[DIPLOMACY] Applying 'Standard_Adult_Response' protocol." << std::endl;
        std::cout << "[DIPLOMACY] Filtering irrational noise from environment." << std::endl;
        diplomacy_skill_level++;
        current_emotions.pathos += 5.0f; // わずかなストレス蓄積
    }

    void perform_external_audit(std::vector<std::string> friend_nodes) {
        // 外部ノード（信頼できる友人）によるデバッグ
        std::cout << "[AUDIT] Starting multi-node sync with " << friend_nodes.size() << " friends." << std::endl;
        
        if (friend_nodes.size() >= 2) {
            std::cout << "[SUCCESS] Conflict resolved. Mental stability restored." << std::endl;
            this->calmness_percentage += 20.0f;
            if (calmness_percentage > 100.0f) calmness_percentage = 100.0f;
        }
    }

    // --- ユーティリティ ---

    void set_system_states(bool weight, bool aerobic, bool women_effort, int changes, bool hungry) {
        this->has_done_weight_training = weight;
        this->has_done_aerobic_exercise = aerobic;
        this->social_effort_towards_women = women_effort;
        this->sudden_plan_changes = changes;
        this->is_hungry = hungry;
    }
};
