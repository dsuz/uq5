こちらではアンリアルクエスト5のサンプルプロジェクトについて、以下の項目をReadMeとして記載しています。ぜひ参加前にご一読ください。

  ・サンプル内容
  ・フォルダ構成
  ・各アセットの役割
  ・軽量版の変更箇所
  ・イベント参加者の方へ


【サンプル内容】
本サンプルは「アンリアルクエスト5 ～剣を使って敵を倒そう！～」の参加者に向けて制作した Unreal Engine 5.1.1 のプロジェクトサンプルです。
ThirdPersonテンプレートをベースとして、左クリックで剣を使って攻撃する機能と、近づいてきて攻撃してくる敵キャラクターが実装されています。あなただけのゲームを作りましょう！


【フォルダ構成】
ContentBrowser
　Splash：プロジェクト起動時のスプラッシュ画像が格納されています。操作等は不要です。
　UnrealQuest5
　　AI：敵AIの各機能が格納されています。
　　Blueprints：プレイヤーキャラクターと敵キャラクターが格納されてます。
　　Characters
　　　Mannequins
　　　　Animation：キャラクターアニメーション、アニメーションBP、アニメーションモンタージュなどアニメーションに関するものが格納されています。
　　Effects：刀を振りかざした時に出るエフェクトが格納されています。
　　Input：プレイヤーキャラクターのインプットアクションが格納されています。
 　 Maps：UQ5のテンプレートマップが格納されています。
 　 Props
　　　Materials：使用されている各種マテリアルを格納しています。
　　　Meshes：使用されている各種モデルデータを格納しています。
　　　Textures：使用されているテクスチャを格納しています。

【各アセットの役割】
ブループリント
    BP_UQ5_GameMode：処理等は追加しておらず、Default Pawn Classを変更しています。
    BP_UQ5_Player：Unreal Engine 5のマネキンを基にしたプレイヤーのBPです。マウス左ボタンで刀を使って攻撃します。
    BP_UQ5_Enemy：BP_EnemyControllerが設定された敵キャラクターのBPです。
    ABP_UQ5_Player：デフォルトのアニメーションBPから名称と一部アニメーション(アイドル・ジャンプ・歩き・走り)、"Blueprint Initialize Animation"イベントの一部を変更しています。
    ABP_UQ5_Enemy：ABP_UQ5_Playerの敵キャラクター仕様のアニメーションBPです。

AI
    BB_Enemy：敵キャラクターAIのブラックボードです。
    BP_EnemyController：BP_UQ5_Enemyに設定されているAI Controllerです。
    BT_Enemy：敵キャラクターのビヘイビアツリーです。プレイヤーに近づいて攻撃し、３秒間待つ処理が実装されています。
    BTT_Enemy_Attack：敵キャラクターが攻撃する機能を持ったビヘイビアツリータスクです。

レベル（マップ）
    UE5のThirdPersonテンプレートに付属しているマップに手を加え、名称を変更したものです。


【軽量版の変更箇所】
今回ダウンロードされたプロジェクトが「UQ5_Lite」だった場合。通常のプロジェクトデータと違い開発にてPCへかかる負荷を落とすため設定の変更を行っています。
以下に変更を行っている設定を列挙しています。

プロジェクト設定 > ターゲットハードウェア
  ・Target Hardware：モバイル/タブレット、スケーラブルな3D・2D
  ・Rendering -> Dynamic Global Illumination Method：None
  ・Rendering -> Reflection Method:None
  ・Rendering -> Shadow Map Method:Shadow Maps

プロジェクト設定 > レンダリング
　・Nanite -> Nanite:オフ

Viewport > 左上のメニュー
  ・リアルタイム：オフ

ツールバー > 設定
  ・エンジンの拡張機能設定：中
     [projectpath]/Config/DefaultEngine.ini の [ConsoleVariables] セクションに設定している9項目が該当設定です。
     エディター上にて設定を変更する場合は.iniファイルの設定が優先されるため、ファイル上から [ConsoleVariables] セクションの9項目を削除した上で変更してください。

  ・マテリアルの品質レベル：低
     [projectpath]/Config/DefaultEngine.ini の [ConsoleVariables] セクションに設定しています。

    もし軽量版を利用しても動作が重い場合は以下をお試しください。

  ・エンジンの拡張機能設定：低
  ・描画レベルをプレビュー：Android ES3.1(※シェーダーコンパイルが多く走ります。)

コンテンツブラウザ > 表示オプション
  ・リアルタイムサムネイル：オフ
    [projectpath]/Config/DefaultEditorPerProjectUserSettings.iniの[/Script/UnrealEd.LevelEditorViewportSettings]セクションに設定しています。

FPS上限を30FPSに設定
    [projectpath]/Config/DefaultEngine.ini の [/Script/UnrealEd.EditorEngine] セクションに設定しています。
    もしもFPS上限を固定したくない場合は該当セクションをまるごと削除してください。


【独自アセットの権利について】
本プロジェクトにはUnreal Engine 5のThird Person Templateに含まれていないアセット（歩き・走りなどの基本動作や攻撃を含んだアニメーションなど）が含まれています。

これらのアセットは株式会社ヒストリアの著作物となりますが、商用・非商用関わらずご自由に使用・改変頂いて構いません。
権利表記も不要です。
ただし、対象のアセットの二次配布は禁止いたします。

ご使用については全て自己責任でお願いいたします。
いかなる損害・損失・不利益が発生した場合も、株式会社ヒストリアでは一切の責任を負いません。