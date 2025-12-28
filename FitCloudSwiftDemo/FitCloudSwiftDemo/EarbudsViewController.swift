//
//  EarbudsViewController.swift
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2025-12-28.
//

import UIKit
import FitCloudKit


class EarbudsViewController: UIViewController {

    // MARK: - 界面元素
    private let scrollView = UIScrollView()
    private let contentStackView = UIStackView()
    
    // EQ
    private let eqTitleLabel = UILabel()
    private let eqValueLabel = UILabel()
    private let eqSegmentedControl = UISegmentedControl(items: [NSLocalizedString("SoundEffect 1", comment: ""),
    NSLocalizedString("SoundEffect 2", comment: ""),
    NSLocalizedString("SoundEffect 3", comment: ""),
    NSLocalizedString("SoundEffect 4", comment: ""),
    NSLocalizedString("SoundEffect 5", comment: ""),
    NSLocalizedString("SoundEffect 6", comment: "")])
    private let eqQueryBtn = UIButton(type: .system)
    private let eqSetBtn = UIButton(type: .system)
    
    // 降噪
    private let nrTitleLabel = UILabel()
    private let nrValueLabel = UILabel()
    private let nrSegmentedControl = UISegmentedControl(items: [NSLocalizedString("Off", comment: ""),
                                                              NSLocalizedString("On", comment: ""),
                                                              NSLocalizedString("Transparency", comment: "")])
    private let nrQueryBtn = UIButton(type: .system)
    private let nrSetBtn = UIButton(type: .system)
    
    // 低延迟
    private let llTitleLabel = UILabel()
    private let llValueLabel = UILabel()
    private let llSegmentedControl = UISegmentedControl(items: [NSLocalizedString("Off", comment: ""),
                                                              NSLocalizedString("On", comment: "")])
    private let llQueryBtn = UIButton(type: .system)
    private let llSetBtn = UIButton(type: .system)
    
    // 状态
    private let statusTitleLabel = UILabel()
    private let statusTextView = UITextView()
    private let statusQueryBtn = UIButton(type: .system)
    
    // 固件版本
    private let fwTitleLabel = UILabel()
    private let fwValueLabel = UILabel()
    private let fwQueryBtn = UIButton(type: .system)
    
    // 查找耳机
    private let findTitleLabel = UILabel()
    private let findStatusLabel = UILabel()
    private let findQueryBtn = UIButton(type: .system)
    private let findLeftBtn = UIButton(type: .system)
    private let findRightBtn = UIButton(type: .system)
    private let stopFindLeftBtn = UIButton(type: .system)
    private let stopFindRightBtn = UIButton(type: .system)
    
    @IBAction func onGoBack(_ sender: Any) {
        navigationController?.popViewController(animated: true)
    }
    
    // MARK: - 生命周期
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground
        setupUI()
        setupActions()
    }
    
    // MARK: - 私有方法
    private func setupUI() {
        // ScrollView & StackView
        scrollView.translatesAutoresizingMaskIntoConstraints = false
        contentStackView.translatesAutoresizingMaskIntoConstraints = false
        contentStackView.axis = .vertical
        contentStackView.spacing = 16
        contentStackView.alignment = .fill
        contentStackView.distribution = .fill
        contentStackView.isLayoutMarginsRelativeArrangement = true
        contentStackView.layoutMargins = UIEdgeInsets(top: 20, left: 20, bottom: 20, right: 20)
        
        view.addSubview(scrollView)
        scrollView.addSubview(contentStackView)
        
        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 50),
            scrollView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            
            contentStackView.topAnchor.constraint(equalTo: scrollView.topAnchor),
            contentStackView.leadingAnchor.constraint(equalTo: scrollView.leadingAnchor),
            contentStackView.trailingAnchor.constraint(equalTo: scrollView.trailingAnchor),
            contentStackView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
            contentStackView.widthAnchor.constraint(equalTo: scrollView.widthAnchor)
        ])
        
        // 通用样式
        func labelStyle(_ label: UILabel, text: String, font: UIFont = .systemFont(ofSize: 16), color: UIColor = .label) {
            label.text = text
            label.font = font
            label.textColor = color
            label.numberOfLines = 0
        }
        
        func buttonStyle(_ btn: UIButton, title: String) {
            btn.setTitle(title, for: .normal)
            btn.setTitleColor(.white, for: .normal)
            btn.backgroundColor = .systemBlue
            btn.layer.cornerRadius = 6
            btn.titleLabel?.font = .systemFont(ofSize: 14)
            btn.contentEdgeInsets = UIEdgeInsets(top: 6, left: 12, bottom: 6, right: 12)
        }
        
        func horizontalStack(spacing: CGFloat = 8) -> UIStackView {
            let stack = UIStackView()
            stack.axis = .horizontal
            stack.spacing = spacing
            stack.distribution = .fill
            stack.alignment = .center
            return stack
        }
        
        func separator() -> UIView {
            let v = UIView()
            v.backgroundColor = .separator
            v.heightAnchor.constraint(equalToConstant: 0.5).isActive = true
            return v
        }
        
        // EQ 区域
        labelStyle(eqTitleLabel, text: NSLocalizedString("EQ Mode", comment: "EQ section title"), font: .boldSystemFont(ofSize: 18))
        labelStyle(eqValueLabel, text: String(format: NSLocalizedString("Current：%@", comment: "EQ current value placeholder"), NSLocalizedString("Unknown", comment: "Unknown")))
        eqSegmentedControl.selectedSegmentIndex = 0
        buttonStyle(eqQueryBtn, title: NSLocalizedString("Query", comment: "EQ query button"))
        buttonStyle(eqSetBtn, title: NSLocalizedString("Set", comment: "EQ set button"))
        let eqBtnStack = horizontalStack()
        eqBtnStack.addArrangedSubview(eqQueryBtn)
        eqBtnStack.addArrangedSubview(eqSetBtn)
        let eqStack = UIStackView(arrangedSubviews: [eqTitleLabel, eqValueLabel, eqSegmentedControl, eqBtnStack])
        eqStack.axis = .vertical
        eqStack.spacing = 8
        contentStackView.addArrangedSubview(eqStack)
        contentStackView.addArrangedSubview(separator())
        
        // 降噪区域
        labelStyle(nrTitleLabel, text: NSLocalizedString("Noise Reduction Mode", comment: "NR section title"), font: .boldSystemFont(ofSize: 18))
        labelStyle(nrValueLabel, text: String(format: NSLocalizedString("Current：%@", comment: "NR current value placeholder"), NSLocalizedString("Unknown", comment: "Unknown")))
        nrSegmentedControl.selectedSegmentIndex = 0
        buttonStyle(nrQueryBtn, title: NSLocalizedString("Query", comment: "NR query button"))
        buttonStyle(nrSetBtn, title: NSLocalizedString("Set", comment: "NR set button"))
        let nrBtnStack = horizontalStack()
        nrBtnStack.addArrangedSubview(nrQueryBtn)
        nrBtnStack.addArrangedSubview(nrSetBtn)
        let nrStack = UIStackView(arrangedSubviews: [nrTitleLabel, nrValueLabel, nrSegmentedControl, nrBtnStack])
        nrStack.axis = .vertical
        nrStack.spacing = 8
        contentStackView.addArrangedSubview(nrStack)
        contentStackView.addArrangedSubview(separator())
        
        // 低延迟区域
        labelStyle(llTitleLabel, text: NSLocalizedString("Low Latency Mode", comment: "LL section title"), font: .boldSystemFont(ofSize: 18))
        labelStyle(llValueLabel, text: String(format: NSLocalizedString("Current：%@", comment: "LL current value placeholder"), NSLocalizedString("Unknown", comment: "Unknown")))
        llSegmentedControl.selectedSegmentIndex = 0
        buttonStyle(llQueryBtn, title: NSLocalizedString("Query", comment: "LL query button"))
        buttonStyle(llSetBtn, title: NSLocalizedString("Set", comment: "LL set button"))
        let llBtnStack = horizontalStack()
        llBtnStack.addArrangedSubview(llQueryBtn)
        llBtnStack.addArrangedSubview(llSetBtn)
        let llStack = UIStackView(arrangedSubviews: [llTitleLabel, llValueLabel, llSegmentedControl, llBtnStack])
        llStack.axis = .vertical
        llStack.spacing = 8
        contentStackView.addArrangedSubview(llStack)
        contentStackView.addArrangedSubview(separator())
        
        // 状态区域
        labelStyle(statusTitleLabel, text: NSLocalizedString("Earbuds Status", comment: "Status section title"), font: .boldSystemFont(ofSize: 18))
        statusTextView.isEditable = false
        statusTextView.font = .systemFont(ofSize: 14)
        statusTextView.backgroundColor = .secondarySystemBackground
        statusTextView.layer.cornerRadius = 6
        statusTextView.text = NSLocalizedString("Tap to query status", comment: "Status placeholder text")
        statusTextView.heightAnchor.constraint(equalToConstant: 100).isActive = true
        buttonStyle(statusQueryBtn, title: NSLocalizedString("Query Status", comment: "Status query button"))
        let statusStack = UIStackView(arrangedSubviews: [statusTitleLabel, statusTextView, statusQueryBtn])
        statusStack.axis = .vertical
        statusStack.spacing = 8
        contentStackView.addArrangedSubview(statusStack)
        contentStackView.addArrangedSubview(separator())
        
        // 固件版本区域
        labelStyle(fwTitleLabel, text: NSLocalizedString("Firmware Version", comment: "FW section title"), font: .boldSystemFont(ofSize: 18))
        labelStyle(fwValueLabel, text: String(format: NSLocalizedString("Current：%@", comment: "FW current value placeholder"), NSLocalizedString("Unknown", comment: "Unknown")))
        buttonStyle(fwQueryBtn, title: NSLocalizedString("Query", comment: "FW query button"))
        let fwStack = UIStackView(arrangedSubviews: [fwTitleLabel, fwValueLabel, fwQueryBtn])
        fwStack.axis = .vertical
        fwStack.spacing = 8
        contentStackView.addArrangedSubview(fwStack)
        contentStackView.addArrangedSubview(separator())
        
        // 查找耳机区域
        labelStyle(findTitleLabel, text: NSLocalizedString("Find Earbuds", comment: "Find section title"), font: .boldSystemFont(ofSize: 18))
        labelStyle(findStatusLabel, text: String(format: NSLocalizedString("Find Status：%@", comment: "Find status placeholder"), NSLocalizedString("Unknown", comment: "Unknown")))
        buttonStyle(findQueryBtn, title: NSLocalizedString("Query Status", comment: "Find query button"))
        buttonStyle(findLeftBtn, title: NSLocalizedString("Find Left", comment: "Find left button"))
        buttonStyle(findRightBtn, title: NSLocalizedString("Find Right", comment: "Find right button"))
        buttonStyle(stopFindLeftBtn, title: NSLocalizedString("Stop Left", comment: "Stop find left button"))
        buttonStyle(stopFindRightBtn, title: NSLocalizedString("Stop Right", comment: "Stop find right button"))
        let findBtnRow1 = horizontalStack()
        findBtnRow1.addArrangedSubview(findLeftBtn)
        findBtnRow1.addArrangedSubview(findRightBtn)
        let findBtnRow2 = horizontalStack()
        findBtnRow2.addArrangedSubview(stopFindLeftBtn)
        findBtnRow2.addArrangedSubview(stopFindRightBtn)
        let findStack = UIStackView(arrangedSubviews: [findTitleLabel, findStatusLabel, findQueryBtn, findBtnRow1, findBtnRow2])
        findStack.axis = .vertical
        findStack.spacing = 8
        contentStackView.addArrangedSubview(findStack)
    }
    
    private func setupActions() {
        eqQueryBtn.addTarget(self, action: #selector(queryEQ), for: .touchUpInside)
        eqSetBtn.addTarget(self, action: #selector(setEQ), for: .touchUpInside)
        nrQueryBtn.addTarget(self, action: #selector(queryNR), for: .touchUpInside)
        nrSetBtn.addTarget(self, action: #selector(setNR), for: .touchUpInside)
        llQueryBtn.addTarget(self, action: #selector(queryLL), for: .touchUpInside)
        llSetBtn.addTarget(self, action: #selector(setLL), for: .touchUpInside)
        statusQueryBtn.addTarget(self, action: #selector(queryStatus), for: .touchUpInside)
        fwQueryBtn.addTarget(self, action: #selector(queryFW), for: .touchUpInside)
        findQueryBtn.addTarget(self, action: #selector(queryFindStatus), for: .touchUpInside)
        findLeftBtn.addTarget(self, action: #selector(findLeft), for: .touchUpInside)
        findRightBtn.addTarget(self, action: #selector(findRight), for: .touchUpInside)
        stopFindLeftBtn.addTarget(self, action: #selector(stopFindLeft), for: .touchUpInside)
        stopFindRightBtn.addTarget(self, action: #selector(stopFindRight), for: .touchUpInside)
    }
    
    // MARK: - 业务方法
    @objc private func queryEQ() {
        FitCloudKit.queryEarbudsEqualizer { [weak self] success, currentEQ, error in
            DispatchQueue.main.async {
                if success {
                    self?.eqValueLabel.text = String(format: NSLocalizedString("Current：%@", comment: "EQ current value placeholder"), currentEQ.toEQDesc())
                    self?.eqSegmentedControl.selectedSegmentIndex = max(0, currentEQ.rawValue)
                } else {
                    self?.showToast(String(format: NSLocalizedString("Query failed：%@", comment: "Query failed placeholder"), error?.localizedDescription ?? NSLocalizedString("Unknown error", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func setEQ() {
        let idx = eqSegmentedControl.selectedSegmentIndex
        let eq = FitCloudPresetEQ(rawValue: idx) ?? .soundEffect1
        FitCloudKit.setEarbudsEqualizer(eq) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("SetSuccess", comment: "Set success toast") : String(format: NSLocalizedString("SetFailed", comment: "Set failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                
            }
        }
    }
    
    @objc private func queryNR() {
        FitCloudKit.queryEarbudsNoiseReductionMode { [weak self] success, mode, error in
            DispatchQueue.main.async {
                if success {
                    self?.nrValueLabel.text = String(format: NSLocalizedString("Current：%@", comment: "NR current value placeholder"), mode.toNRDesc())
                    self?.nrSegmentedControl.selectedSegmentIndex = max(0, mode.rawValue)
                } else {
                    self?.showToast(String(format: NSLocalizedString("QueryFailed", comment: "Query failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func setNR() {
        let idx = nrSegmentedControl.selectedSegmentIndex
        let mode: FitCloudNoiseReductionMode
        switch idx {
        case 0: mode = .off
        case 1: mode = .on
        default: mode = .transparency
        }
        FitCloudKit.setEarbudsNoiseReductionMode(mode) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("SetSuccess", comment: "") : String(format: NSLocalizedString("SetFailed", comment: ""), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "")))
                
            }
        }
    }
    
    @objc private func queryLL() {
        FitCloudKit.queryEarbudsLowLatencyMode { [weak self] success, mode, error in
            DispatchQueue.main.async {
                if success {
                    self?.llValueLabel.text = String(format: NSLocalizedString("Current：%@", comment: "LL current value placeholder"), mode.toLLDesc())
                    self?.llSegmentedControl.selectedSegmentIndex = max(0, mode.rawValue)
                } else {
                    self?.showToast(String(format: NSLocalizedString("QueryFailed", comment: "Query failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func setLL() {
        let idx = llSegmentedControl.selectedSegmentIndex
        let mode: FitCloudLowLatencyMode = idx == 0 ? .off : .on
        FitCloudKit.setEarbudsLowLatencyMode(mode) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("SetSuccess", comment: "") : String(format: NSLocalizedString("SetFailed", comment: ""), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "")))
               
            }
        }
    }
    
    @objc private func queryStatus() {
        FitCloudKit.queryEarbudsStatus { [weak self] success, statusInfo, error in
            DispatchQueue.main.async {
                if success, let info = statusInfo {
                    var text = ""
                    text += String(format: NSLocalizedString("LeftConnection: %@\n", comment: "Left earbud connection status"), info.leftConnectionStatus.toConnectionDesc())
                    text += String(format: NSLocalizedString("RightConnection: %@\n", comment: "Right earbud connection status"), info.rightConnectionStatus.toConnectionDesc())
                    text += String(format: NSLocalizedString("LeftInCase: %@\n", comment: "Left earbud in-case status"), info.leftInCaseStatus.toInCaseDesc())
                    text += String(format: NSLocalizedString("RightInCase: %@", comment: "Right earbud in-case status"), info.rightInCaseStatus.toInCaseDesc())
                    self?.statusTextView.text = text
                } else {
                    self?.showToast(String(format: NSLocalizedString("QueryFailed: %@", comment: "Query failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func queryFW() {
        FitCloudKit.queryEarbudsFirmwareVersion { [weak self] success, version, error in
            DispatchQueue.main.async {
                if success, let v = version {
                    self?.fwValueLabel.text = String(format: NSLocalizedString("Current：%@", comment: "FW current value placeholder"), v)
                } else {
                    self?.showToast(String(format: NSLocalizedString("QueryFailed", comment: "Query failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func queryFindStatus() {
        FitCloudKit.queryEarbudsFindStatusInfo { [weak self] success, statusInfo, error in
            DispatchQueue.main.async {
                if success, let info = statusInfo {
                    self?.findStatusLabel.text = String(format: NSLocalizedString("Find Status：Left %@ / Right %@", comment: "Find status label"), info.leftFindStatus.toFindDesc(), info.rightFindStatus.toFindDesc())
                } else {
                    self?.showToast(String(format: NSLocalizedString("QueryFailed", comment: "Query failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
                }
            }
        }
    }
    
    @objc private func findLeft() {
        FitCloudKit.findEarbud(with: .left) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("FindLeftStarted", comment: "Find left started toast") : String(format: NSLocalizedString("FindLeftFailed", comment: "Find left failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
            }
        }
    }
    
    @objc private func findRight() {
        FitCloudKit.findEarbud(with: .right) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("FindRightStarted", comment: "Find right started toast") : String(format: NSLocalizedString("FindRightFailed", comment: "Find right failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
            }
        }
    }
    
    @objc private func stopFindLeft() {
        FitCloudKit.stopFindEarbud(with: .left) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("FindLeftStopped", comment: "Find left stopped toast") : String(format: NSLocalizedString("StopFindLeftFailed", comment: "Stop find left failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
            }
        }
    }
    
    @objc private func stopFindRight() {
        FitCloudKit.stopFindEarbud(with: .right) { [weak self] success, error in
            DispatchQueue.main.async {
                self?.showToast(success ? NSLocalizedString("FindRightStopped", comment: "Find right stopped toast") : String(format: NSLocalizedString("StopFindRightFailed", comment: "Stop find right failed toast"), error?.localizedDescription ?? NSLocalizedString("UnknownError", comment: "Unknown error")))
            }
        }
    }
    
    // MARK: - 工具方法
    private func showToast(_ message: String) {
        let toast = UIAlertController(title: nil, message: message, preferredStyle: .alert)
        present(toast, animated: true)
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.5) {
            toast.dismiss(animated: true)
        }
    }
}

// MARK: - 枚举扩展（国际化描述）
extension FitCloudPresetEQ {
    func toEQDesc() -> String {
        switch self {
        case .soundEffect1: return NSLocalizedString("SoundEffect 1", comment: "EQ preset 1")
        case .soundEffect2: return NSLocalizedString("SoundEffect 2", comment: "EQ preset 2")
        case .soundEffect3: return NSLocalizedString("SoundEffect 3", comment: "EQ preset 3")
        case .soundEffect4: return NSLocalizedString("SoundEffect 4", comment: "EQ preset 4")
        case .soundEffect5: return NSLocalizedString("SoundEffect 5", comment: "EQ preset 5")
        case .soundEffect6: return NSLocalizedString("SoundEffect 6", comment: "EQ preset 6")
        default: return NSLocalizedString("Unknown", comment: "Unknown EQ preset")
        }
    }
}

extension FitCloudNoiseReductionMode {
    func toNRDesc() -> String {
        switch self {
        case .off: return NSLocalizedString("Off", comment: "Noise reduction off")
        case .on: return NSLocalizedString("On", comment: "Noise reduction on")
        case .transparency: return NSLocalizedString("Transparency", comment: "Transparency mode")
        default: return NSLocalizedString("Unknown", comment: "Unknown noise reduction mode")
        }
    }
}

extension FitCloudLowLatencyMode {
    func toLLDesc() -> String {
        switch self {
        case .off: return NSLocalizedString("Off", comment: "Low latency off")
        case .on: return NSLocalizedString("On", comment: "Low latency on")
        default: return NSLocalizedString("Unknown", comment: "Unknown low latency mode")
        }
    }
}

extension FitCloudEarbudConnectionStatus {
    func toConnectionDesc() -> String {
        switch self {
        case .connected: return NSLocalizedString("Connected", comment: "Earbud connected")
        case .disconnected: return NSLocalizedString("Disconnected", comment: "Earbud disconnected")
        default: return NSLocalizedString("Unknown", comment: "Unknown connection status")
        }
    }
}

extension FitCloudEarbudInCaseStatus {
    func toInCaseDesc() -> String {
        switch self {
        case .in: return NSLocalizedString("In Case", comment: "Earbud in charging case")
        case .out: return NSLocalizedString("Out of Case", comment: "Earbud out of charging case")
        default: return NSLocalizedString("Unknown", comment: "Unknown in-case status")
        }
    }
}

extension FitCloudEarbudFindStatus {
    func toFindDesc() -> String {
        switch self {
        case .finding: return NSLocalizedString("Finding", comment: "Earbud finding in progress")
        case .notFinding: return NSLocalizedString("Not Finding", comment: "Earbud not finding")
        default: return NSLocalizedString("Unknown", comment: "Unknown find status")
        }
    }
}
